// Serialize a web-tree-sitter CST node into the JSON shape consumed by
// chord2mml-core's cst_to_ast (same shape as tonejs-mml-to-json's
// nodeToCSTJson): named children with a field name go to `fields`,
// other named children go to `children`.
export function nodeToCSTJson(node) {
  const sourceText = node.tree.rootNode.text;
  const encoder = new TextEncoder();
  const byteOffsets = new Map([[0, 0]]);

  const utf8ByteOffset = (index) => {
    if (!byteOffsets.has(index)) {
      byteOffsets.set(index, encoder.encode(sourceText.slice(0, index)).length);
    }
    return byteOffsets.get(index);
  };

  return serializeNode(node, utf8ByteOffset);
}

function serializeNode(node, utf8ByteOffset) {
  const result = {
    type: node.type,
    text: node.text,
    source_range: {
      start: utf8ByteOffset(node.startIndex),
      end: utf8ByteOffset(node.endIndex)
    },
    children: [],
    fields: {}
  };

  for (let i = 0; i < node.namedChildCount; i++) {
    const child = node.namedChild(i);
    if (!child) {
      continue;
    }

    const fieldName = node.fieldNameForNamedChild(i);
    const childJson = serializeNode(child, utf8ByteOffset);

    if (fieldName) {
      if (!result.fields[fieldName]) {
        result.fields[fieldName] = [];
      }
      result.fields[fieldName].push(childJson);
    } else {
      result.children.push(childJson);
    }
  }

  return result;
}

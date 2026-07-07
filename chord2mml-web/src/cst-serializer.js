// Serialize a web-tree-sitter CST node into the JSON shape consumed by
// chord2mml-core's cst_to_ast (same shape as tonejs-mml-to-json's
// nodeToCSTJson): named children with a field name go to `fields`,
// other named children go to `children`.
export function nodeToCSTJson(node) {
  const result = {
    type: node.type,
    text: node.text,
    children: [],
    fields: {}
  };

  for (let i = 0; i < node.namedChildCount; i++) {
    const child = node.namedChild(i);
    if (!child) {
      continue;
    }

    const fieldName = node.fieldNameForNamedChild(i);
    const childJson = nodeToCSTJson(child);

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

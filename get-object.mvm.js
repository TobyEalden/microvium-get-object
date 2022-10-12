console.log = vmImport(1);
const getResource = vmImport(2);

function main() {
  console.log('starting');

  const res = getResource("@root");

  console.log(res.name);
}

function createObject() {
  return {};
}

function setProp(obj, prop, val) {
  console.log("set property " + prop + " to " + val);
  obj[prop] = val;
}

vmExport(1, createObject);
vmExport(2, setProp);
vmExport(1234, main);

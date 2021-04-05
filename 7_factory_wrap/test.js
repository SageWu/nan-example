let addon;
try {
  addon = require("./build/Release/example");
} catch (error) {
  addon = require("./build/Debug/example");
}

(function () {
  const createValue = addon.createValue;
  const value = createValue(0);
  console.log(value);
  console.log(value.add(2));
  console.log(value);
})();
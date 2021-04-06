let addon;
try {
  addon = require("./build/Release/example");
} catch (error) {
  addon = require("./build/Debug/example");
}

(function () {
  const { createValue, add } = addon;
  const value1 = createValue(10);
  const value2 = createValue(20);
  console.log(value1, value2);
  console.log(add(value1, value2));
})();
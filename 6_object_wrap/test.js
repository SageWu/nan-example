let addon;
try {
  addon = require("./build/Release/example");
} catch (error) {
  addon = require("./build/Debug/example");
}

(function () {
  const ValueWrap = addon.ValueWrap;
  const value = new ValueWrap(0);
  console.log(value);
  console.log(value.add(1));
  console.log(value);
})();
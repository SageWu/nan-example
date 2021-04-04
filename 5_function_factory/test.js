let addon;
try {
  addon = require("./build/Release/example");
} catch (error) {
  addon = require("./build/Debug/example");
}

(function () {
  const fn = addon.createFunction();
  console.log(fn("hello"));
})();
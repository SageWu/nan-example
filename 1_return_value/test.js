let addon;
try {
  addon = require("./build/Release/example");
} catch (error) {
  addon = require("./build/Debug/example");
}

(function() {
  console.log(addon.getString());
})();
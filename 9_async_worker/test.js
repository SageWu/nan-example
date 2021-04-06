let addon;
try {
  addon = require("./build/Release/example");
} catch (error) {
  addon = require("./build/Debug/example");
}

(function () {
  const { calculateAsync } = addon;
  calculateAsync(2, (err, res) => {
    console.log(res);
  });
})();
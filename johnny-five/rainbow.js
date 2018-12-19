var temporal = require("temporal");
var five = require("johnny-five");
var board = new five.Board();



board.on("ready", function() {
    const led = new five.Led.RGB({
        pins: {
            red: 9,
            blue: 11,
            green: 10
        },
        isAnode: true
    })

    let index = 0;
    var rainbow = ["FF0000", "FF7F00", "FFFF00", "00FF00", "0000FF", "4B0082", "8F00FF"];
    this.loop(1000, function(){
        led.color(rainbow[index++]);
        if(index === rainbow.length){
            index = 0;
        }
    })
  this.on('exit', () => led.on)
});
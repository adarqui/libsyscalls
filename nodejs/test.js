var sc = require('./syscalls.js')

var ticks = sc.ticks()
var stats = sc.times()

console.log("ticks:", ticks)

console.log("stats:", stats)

for(var v = 0; v < 1000000000; v++) { Math.random()^3 ; }

stats = sc.times()

console.log("stats:", stats)

/*
 still playing with this.
sc.execve({
	file : "/bin/ls",
	argv: ["-al"],
	envp : [],
})
*/

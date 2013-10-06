/* syscalljs -- adarqui && github.com/adarqui && adarq.org */

var deps = {
	sc	: require('./build/Release/syscallsjs'),
}

var _times = function(o) {
	return deps.sc.times()
}

var _ticks = function(o) {
	return deps.sc.ticks()
}

var _execve = function(o) {
	return deps.sc.execve(o.file, o.argv, o.envp)
}

module.exports = {
	times : _times,
	ticks : _ticks,
	execve : _execve,
}

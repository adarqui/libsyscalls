libsyscalls is just a small repo I created in order to add support to languages which are missing specific syscalls from their api etc.

For example, I couldn't find "times()" in node.js. Times returns the time spent in system space and user space. It may actually exist in node.js but I couldn't find it so I just wrote my own native binding. If I find myself needing to write syscall support for X language, i'll add it to this repo.

peace.

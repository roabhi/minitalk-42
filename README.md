# minitalk-42

Minitalk is a project for the 42 coding school.

The goal is to create a communication program in a client-server fashion.

The requisites are:

- Client must be launch first, then show its PID.
- Client will take the following parameters
	- Server PID.
	- String to send.
- Client must send the string passed as parameter to the server. Then the server must show it.
- Communication between programs must only use UNIX signals.
- The server must be capable of displaying the output fast enough.
- The server must be capable of getting different strings from different clients consecutively without any reboot
- Only two signals are allowed: SIGUSR1 and SIGUSR2.

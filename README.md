h1. Arduino <-> ATARI

Der Plan: ein Arduino als Universal-Peripherie für 8bit-Ataris:

* Diskettenlaufwerk emulieren ähnlich SIO2SD
** Disk Images von SD-Karte 
** Disk Images vom PC über Arduino USB
* Nintendo Wii Nunchuk Controller (über Arduino I2C) als Joystick-Ersatz 
* Drucker- und Modem-Emulation

Diskettenlaufwerke, Drucker und Modems wurden über einen speziellen seriellen Bus (SIO - Serial I/O) an die 8bit-Ataris angeschlossen. Der Bus hat dabei einen Master (den Atari) und bis zu 256 Clients (Laufwerke etc.). Wesentlich für die Funktionalität sind nur 4 Leitungen: Masse, Command zum Einleiten von Kommandos des Masters an Clients, sowie Data Out und In. Übertragen wird idR. mit 19200 Bit/s, 8 Datenbits, je ein Start- und Stop-Bit, kein Paritätsbit. Höhere Übertragungsgeschwindigkeiten sind möglich, erfordern aber angepasste Software.

Die Joystickports sind einfache TTL Eingänge die als aktiv gelten wenn
sie gegen Masse geschaltet werden.

Die Nunchuk-Controller von Nintendo kommunizieren über I2C, können also einfach vom Arduino angesprochen werden. Einziges Problem ist das alle Nunchuks fest auf derselben I2C Adresse liegen, um mehr als einen Controller ansprechen zu können muss also ein einfacher Multiplexer implementiert werden.

# Hardware beschaffen 
## Arduino Mega 2560 *done*
## LCD Display Shield *done*
## Nunchuk *done*
## DSUB-9 (femal) Kabel *done*
## Atari SIO Kabel *done*
## 4066 o.ä. für I2C multiplexing *in progress*
# Software
## Nunchuk auslesen *done*
## Nunchuk X/Y-Werte in Digitaloutput an Atari Joystickport wandeln *done*
## Build System *done*
## SIO Interface *in progres*

h2. Next Steps

* Simple serial reading of Ataris SIO serial output

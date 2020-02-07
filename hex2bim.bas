SCREEN 0
_TITLE "hex2bim by aolvos"
OPEN "splash.hex" FOR INPUT AS #1
OPEN "splash.bim" FOR OUTPUT AS #2
PRINT "Processing..."
DO UNTIL EOF(1)
    INPUT #1, n$
    d% = VAL("&H" + n$)
    PRINT #2, CHR$(d%);
LOOP
CLOSE #1
CLOSE #2
SYSTEM

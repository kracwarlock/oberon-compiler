MODULE LTESQ;
IMPORT In, Out;

TYPE
  y = INTEGER;
  rc = RECORD a, b, c: POINTER TO ARRAY OF INTEGER; d: ARRAY OF INTEGER; END;
  rc1 = RECORD a, b, c: POINTER TO ARRAY OF INTEGER; d: ARRAY OF INTEGER; END;
  pi = POINTER TO ARRAY OF INTEGER;

VAR 
  v1 : ARRAY 10 OF INTEGER;
  v2: INTEGER;
  i: INTEGER;
  a1 : rc;
  a2 : rc1;
  a3 : pi;

BEGIN
  a3 := a1;
  i := 1;
  WHILE i < 11 DO
  	v1[i] := 10;
  	i := i + 1;
  END;

  v2 := v1[10];
  
END LTESQ.
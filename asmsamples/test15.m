MODULE LTESQ;
IMPORT In, Out;

TYPE
  y = INTEGER;

VAR 
  v1 : ARRAY 10 OF INTEGER;
  v2: INTEGER;
  i: INTEGER;

BEGIN
  i := 1;
  WHILE i < 11 DO
  	v1[i] := 10;
  	i := i + 1;
  END;

  v2 := v1[10];
  
END LTESQ.
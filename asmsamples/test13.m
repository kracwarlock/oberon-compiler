MODULE LTESQ;
IMPORT In, Out;

TYPE
  y = INTEGER;
  q = BOOLEAN;
  rc = RECORD a, b, c: POINTER TO ARRAY OF INTEGER; d: ARRAY OF INTEGER; END;
  rc1 = RECORD a, b, c: POINTER TO ARRAY OF INTEGER; d: ARRAY OF INTEGER; END;

VAR 
  v1,v2,v3 : y;
  b1,b2 : rc;
  g1 : rc1;
  m : q;

BEGIN
  v1 := 3;
  v2 := 8;
  v3 := 0;
  IF b1 IS rc THEN
    v3 := 10;
  ELSE
    v3 := 20;
  END;
  IF b1 IS y THEN
    v1 := 60;
  ELSE
    v1 := 50;
  END;
END LTESQ.
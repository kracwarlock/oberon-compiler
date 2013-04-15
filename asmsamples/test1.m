MODULE LTESQ;
IMPORT In, Out;

TYPE
  y = INTEGER;

VAR 
  v1 : y;

BEGIN
  v1 := 7;
  WHILE v1 < 10 DO
        v1 := v1 + 2;
  END;
END LTESQ.
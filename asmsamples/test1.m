MODULE LTESQ;
IMPORT In, Out;

TYPE
  y = INTEGER;

VAR 
  v1 : y;

BEGIN
  v1 := 0;
  WHILE v1 < 100 DO
        v1 := v1 + 1;
  END;
END LTESQ.
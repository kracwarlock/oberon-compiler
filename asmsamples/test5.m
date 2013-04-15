MODULE LTESQ;
IMPORT In, Out;

TYPE
  y = INTEGER;

VAR 
  v1, v2, v3 : y;

BEGIN
  v1 := 7;
  v2 := 0;
  v3 := 0;
  IF v1 > 5 THEN
      WHILE v2 < 10 DO
        v2 := v2 + 1;
      END;
  END;
END LTESQ.
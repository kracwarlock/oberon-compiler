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
  REPEAT
        v1 := v1 + 2;
        IF v1 < 9 THEN
          v2 := 10;
        END;
  UNTIL v1 < 10;
END LTESQ.
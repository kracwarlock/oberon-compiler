MODULE TEST;
IMPORT In, Out;

TYPE
  y = INTEGER;

VAR 
  v1, v2, v3 : y;

BEGIN
  v1 := 7;
  v2 := 0;
  v3 := 0;
  WHILE v1 < 10 DO
        v1 := v1 + 2;
        IF v1 > 9 THEN
        	v2 := 7;
        END;
        IF v1 > 8 THEN
        	v3 := 16;
        END;
  END;
END TEST.
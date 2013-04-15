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
        WHILE v2 <= v1 DO
          v2 := v2 + 1;
        END;
        v1 := v1 + 1;
  END;
END TEST.
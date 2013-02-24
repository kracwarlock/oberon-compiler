 MODULE Example;


    PROCEDURE ArraySum(r: ARRAY OF INTEGER): INTEGER;
    VAR 
      sum: INTEGER;
      i: INTEGER;
    BEGIN sum := 0;
      WHILE i < r.size DO
        sum := sum + r[i];
      END;
      result := sum;
    END ArraySum;
    
  BEGIN
    ArraySum(vec);
  END Example.
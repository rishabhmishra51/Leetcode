select
  product_id, year AS first_year, quantity,price
from
  Sales
WHERE
  (product_id, year) IN (
    SELECT 
            product_id,  MIN(year) AS year
    FROM Sales
    GROUP BY product_id
  );

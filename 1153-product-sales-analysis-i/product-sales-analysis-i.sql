SELECT Sales.price, Sales.year, Product.product_name
FROM Sales
JOIN Product 
ON Sales.product_id = Product.product_id;
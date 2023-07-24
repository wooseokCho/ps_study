SELECT o.product_id, p.product_name, (sum(o.amount) * p.price) as total_sales
from food_product p 
    left join food_order o 
    on p.product_id = o.product_id
where o.produce_date like '2022-05-%'
group by o.product_id
order by total_sales desc, o.product_id

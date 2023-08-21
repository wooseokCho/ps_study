SELECT b.category as CATEGORY, sum(bs.sales) as TOTAL_SALES
from book b inner join book_sales bs on b.book_id = bs.book_id
where bs.SALES_DATE like '2022-01%'
group by b.category
order by b.category asc

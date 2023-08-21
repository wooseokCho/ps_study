SELECT U.board_id, U.writer_id, U.title, U.price, 
        case
            when U.status = 'SALE' THEN '판매중'
            when U.status =  'RESERVED' THEN '예약중'
            when U.status = 'DONE' THEN '거래완료'
        end as 'STATUS'
from USED_GOODS_BOARD U
where U.CREATED_DATE LIKE '2022-10-05'
order by U.board_id desc

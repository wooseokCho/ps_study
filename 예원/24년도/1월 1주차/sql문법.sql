SELECT member_id, name FROM member_id;
SELECT *  FROM member_id;
SELECT * FROM market_db.member;
SELECT * FROM member
#WHERE문법 - 특정 조건만 조회
SELECT * FROM member
    WHERE mem_number >= 5;
SELECT TRUE OR FALSE AND FALSE; //1
SELECT (TRUE OR FALSE) AND FALSE; //0
SELECT * FROM member
    WHERE height between  160 and 165;
#컬럼값이 경기, 전남, 경남인 데이터 조회
SELECT * FROM member    
    WHERE addr IN("경기", "전남", "경남");

SELECT * FROM member
    WHERE addr = "경기" AND addr = "전남" AND addr = "경남";
SELECT * FROM member WHERE mem_name LIKE "블___";
SELECT * FROM member WHERE mem_name LIKE "블%";
SELECT * FROM member WHERE mem_name LIKE "%블%";
SELECT mam_name, height
    FROM member
    WHERE height > (select height from member where mem_name LIKE "에이핑크")
SELECT * FROM member
    ORDER BY debut_date; 
    #ASC: 오름차순-> 생략 시 기본값
SELECT * FROM member
    WHERE height >= 164
    ORDER BY height DESC, debut_date;
SELECT * FROM member
    LIMIT 3;
SELECT * FROM member
    LIMIT 3, 2;
    LIMIT 2 OFFSET 3;
    LIMIT 3, 2;
    LIMIT 2 OFFSET 3;
#addr의 모든 컬럼 값을 중복을 제거하여 조회
SELECT DISTINCT addr
    FROM member;

SELECT mem_id, SUM(amount) AS "합계"
    FROM buy
    GROUP BY mem_id
    ORDER BY mem_id;

SELECT genre, AVG(price) AS "평균"
    from library
    GROUP BY genre;

SUM(), AVG(), MIN(), MAX(), COUNT(), COUNT(DISTINCT)
SELECT mem_id, SUM(amount*price) AS "총금액"
    FROM buy
    GROUP BY mem_id
    ORDER BY mem_id;
SELECT COUNT(*)
    FROM member;
SELECT COUNT(phone1)
    FROM member;
SELECT SUM(amount*price) AS "총금액"
    FROM buy
    GROUP BY mem_id
    HAVING SUM(amount*price) >= 1000;
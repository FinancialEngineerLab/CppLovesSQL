INSERT INTO 테이블 (
    키1
    ,컬럼2
    ,컬럼3
    ,날짜
)
SELECT X.*
  FROM (
    SELECT
        키1
        ,컬럼2
        ,컬럼3
        ,'20190902' AS 날짜
      FROM 테이블 AS A
     WHERE 날짜 = '20190901'
) AS A
 WHERE NOT EXISTS (
         SELECT
             키1
             ,컬럼2
             ,컬럼3
             ,날짜
           FROM 테이블 AS B
          WHERE A.키1 = B.키1
            AND 날짜 = '20190902'
       )
[출처] [MSSql] 데이터 중복을 피해서 INSERT하기 (NOT EXIST)|작성자 NOZ

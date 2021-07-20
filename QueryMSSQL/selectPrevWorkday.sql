USE [DB]
GO
SET ANSI_NULSS ON
Go
SET QUOTE_IDENTIFIER ON
GO

Create Function [dbo].[nextworkday](@date DATE)
RETURNS DATE
AS
BEGIN

DECLARE @ret DATE
DECLARE @cnt INT
SET @cnt = 1
SET @date = DATEADD(D, 1, @date)
SET @cnt = (SELECT COUNT(*) from dbo.holiday where date = @date)

while (@cnt >0 or datepart(weekday, @date) = '1' or datepart(weekday,@date) ='7')
begin
set @date =dateadd(d,-1,@date)
set @cnt = (select count(*) from dbo.holiday where date =@date)
end
return convert(varchar(10), @date, 121)
end
go

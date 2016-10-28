-- SQL Server 2008

-- Efetua shrink database e retorna espa�o restante de volta ao S.O
-- Obs. Comando demorado e exige muito processamento e acesso a disco do servidor
-- podendo ocasionar em lentid�o, portanto n�o recomendado a execu��o em hor�rio
-- de pico
USE [DatabaseName]
GO
DBCC SHRINKDATABASE(N'DatabaseName' )
GO
DBCC SHRINKFILE (N'Database_Data' , 0, TRUNCATEONLY)
GO

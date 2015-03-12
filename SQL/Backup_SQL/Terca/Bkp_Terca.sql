use master
go
/*
	EFETUANDO BACKUP DO BANCO DE DADOS
*/
-- BACKUP COMPLETO DO BANCO
backup database VolpeApaf to disk= 'c:\Backup_SQL\Terca\VolpeApaf.bak'
go
--- VERIFICA INFORMA��ES DO BANCO
sp_helpdb VolpeApaf
--- CORRIGE EVENTUAIS ERROS NO BANCO DE DADOS
dbcc checkdb ('VolpeApaf')
go
--- EXECUTA CHECKPOINT PARA LIMEZA DO LOG
backup log VolpeApaf with no_log
go
--- DESFRAGMENTA OS ARQUIVOS F�SICOS DO BANCO (DADOS E LOG
dbcc shrinkdatabase ( 'VolpeApaf' , 0 )
go

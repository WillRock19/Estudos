CD C:\BACKUP_SQL\QUINTA\
DEL LOG.TXT
DEL VolpeApaf.bak

osql -S(local) -E -dmaster -iC:\BACKUP_SQL\QUINTA\BKP_QUINTA.SQL -oC:\BACKUP_SQL\QUINTA\LOG.TXT

EXIT
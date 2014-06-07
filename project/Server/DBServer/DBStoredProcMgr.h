#ifndef __DB_STORED��PROCEDURE__
#define __DB_STORED��PROCEDURE__

#include "DBStoredProc.h"

enum DBStoredProcedureID
{

	
    MAX_DBServerDB_STATEMENTS,		
};
class CDBStoredProcedureMgr
{
public:
	CDBStoredProcedureMgr();
	~CDBStoredProcedureMgr();
protected:

	BOOL InitStoredProcedures();

	CDBStoredProcedure* GetStoredProcedure(DBStoredProcedureID SpID);

	std::vector<CDBStoredProcedure*>  m_StoredProcedures;
};


#endif



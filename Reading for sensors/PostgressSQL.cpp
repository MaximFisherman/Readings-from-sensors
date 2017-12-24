#include "stdafx.h"
#include "PostgressSQL.h"

/* Values of Connect postgress */
#define PG_HOST    "127.0.0.1"
#define PG_USER    "postgres"
#define PG_DB      "postgres"
#define PG_PASS    "postgres"
#define PG_PORT    5432

PostgressSQL::PostgressSQL()
{
	char conninfo[] = "user = user password = 1111 dbname = date hostaddr = 127.0.0.1 port = 5432";

	/* Make a connection to the database */
	conn = PQconnectdb(conninfo);

	if (PQstatus(conn) != CONNECTION_OK)
	{
		fprintf(stderr, "Connection to database failed: %s",
			PQerrorMessage(conn));
		system("pause");
		exit_nicely(conn);
	}
}

void PostgressSQL::exit_nicely(PGconn *conn)
{
	PQfinish(conn);
	exit(1);
}

PostgressSQL::~PostgressSQL()
{
}

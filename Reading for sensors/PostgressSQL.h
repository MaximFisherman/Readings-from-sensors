#pragma once
class PostgressSQL
{
public:
	PostgressSQL();
	static void exit_nicely(PGconn *conn);
	~PostgressSQL();

private:
	PGconn     *conn;
	PGresult   *res;
	PGnotify   *notify;
	int         nnotifies;
};


#include <odb/database.hxx>
#include <odb/transaction.hxx>

#include "database.hxx" // create_database

#include "myodb.hxx"
#include "myodb-odb.hxx"

using namespace std;
using namespace odb;

int main(int argc, char* argv[]) {
    unsigned long john_id;
    try {
//        db information is in argv
        auto_ptr<database> db(create_database(argc, argv));
        student test("john","2",29);
        student make("jae","4","3",19);
        transaction t(db->begin ());
        john_id = db->persist(test);
        db->persist(test);
        db->persist(make);
        t.commit ();

        typedef odb::query<student> query;
        typedef odb::result<student> result;

        {
            transaction t (db->begin ());

            result r (db->query<student> (query::age > 0));

            for (result::iterator i (r.begin ()); i != r.end (); ++i)
            {
                cout << "Hello, " << i->get_name () << " " << i->get_sscholl () << "!" << endl;
            }

            t.commit ();
        }

        {
            transaction t (db->begin ());

            auto_ptr<student> joe (db->load<student> (john_id));
            joe->age (joe->get_age () + 1);
            db->update (*joe);

            t.commit ();
        }
    }catch (const odb::exception& e)
    {
        cerr << e.what () << endl;
        return 1;
    }
    return 0;
}
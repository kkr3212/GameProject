
#ifndef _SQL_PSTMT_H_
#define _SQL_PSTMT_H_

#include <my_global.h>
#include <mysql.h>
#include "sql_string.h"
#include "Allocator.h"
#include "sql_result.h"

namespace ex
{

class sql_stmt
{
public:
    friend class sql_conn;
    friend class object_pool<sql_stmt>;

    // release.
    void release( void );

    // set bool value.
    void set_bool( size_t idx_, my_bool bval_ );

    // set int8 value.
    void set_int8( size_t idx_, int8 i8_ );

    // set uint8 value.
    void set_uint8( size_t idx_, uint8 ui8_ );

    // set int16 value.
    void set_int16( size_t idx_, int16 i16_ );

    // set uint16 value.
    void set_uint16( size_t idx_, uint16 ui16_ );

    // set int32 value.
    void set_int32( size_t idx_, int32 i32_ );

    // set uint32 value.
    void set_uint32( size_t idx_, uint32 ui32_ );

    // set int64 value.
    void set_int64( size_t idx_, int64 i64_ );

    // set uint64 value.
    void set_uint64( size_t idx_, uint64 ui64_ );

    // set float value.
    void set_float( size_t idx_, float fval_ );

    // set double value.
    void set_double( size_t idx_, double dval_ );

    // set string.
    void set_string( size_t idx_, char const *str_ );

    // set string.
    void set_string( size_t idx_, char const *str_, size_t sz_ );

    // set blob.
    void set_blob( size_t idx_, void const *ptr_, size_t sz_ );

	// set medium bolb
	void set_medium_blob( size_t idx_, void const *ptr_, size_t sz_ );

protected:
    sql_stmt( void );
    ~sql_stmt( void );

    // bind parameters.
    void _bind( size_t count_ );

private:
    typedef struct _param
    {
        sql_string       buf;
        enum_field_types type;
        my_bool          is_unsigned;
        my_bool          is_null_val;

        _param( void )
            : type( MYSQL_TYPE_NULL ),
              is_unsigned( 0 ),
              is_null_val( 0 )
        {}
    } param_t;

    MYSQL_BIND           *m_bind_;
    size_t                m_count_;   // count of MYSQL_BIND
    map<size_t, param_t>  m_params_;  // parameters.
    sql_string            m_sql_;
};

} // namespace ex

#endif // _SQL_PSTMT_H_
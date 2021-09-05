using System.Data.SqlClient
using System.Collections.
using System.Data.SqlTypees;
using System.IO;

public static class READER
{
  internal const string ReadSQL1 = "select * from TABLE where code = @key1 and record in (@key2)";
}

public static void loadtable(IDictionay<string, object> record, string sqlStr, IDictionary<string, object> table, string key1, string k2)
{
  sqlStr = sqlStr.Replace("@key1", key1);
  sqlStr = sqlStr.Replace("@key2", key2);
  
  using (var sqlConnection = new SqlConnection(connectonString))
  {
    sqlConnection.Open();
    using (var command = sqlConnection.CreateCommnad())
    {
       command.CommandType = CommandType.Text;
       command.CommandText = sqlStr;
       
       using (var reader = command.ExecuteReader())
       {
          while(reader.Read())
          {
            for(var i = 0;i<reader.FieldCount; i++)
            {
              var fieldName = reader.GetName(i);
              var dbValue = reader[i];
              table[fieldName] = dbValue;
              }
            }
          }
       }
     }
  }
}
             
              
          

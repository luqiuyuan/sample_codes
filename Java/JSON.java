import org.json.JSONObject;
import org.json.JSONArray;

public class JSON {

  public static void main(String[] args) {
    String json_str = "{" +
                        "\"node00\": {" +
                          "\"node10\": 1," +
                          "\"node11\": \"lalala\"," +
                          "\"node12\": null" +
                        "}," +
                        "\"node01\": [true, false]" +
                      "}";
    
    // Read from a string
    JSONObject json_obj_read = new JSONObject(json_str);
    JSONObject node00_read = (JSONObject) json_obj_read.get("node00");
    JSONArray node01_read = (JSONArray) json_obj_read.get("node01");
    int node10_read = node00_read.getInt("node10");
    String node11_read = node00_read.getString("node11");
    Object node12_read = node00_read.get("node12");

    // Write to a string
    JSONObject json_obj_to_write = new JSONObject();
    JSONObject node00_to_write = new JSONObject();
    JSONArray node01_to_write = new JSONArray();
    node00_to_write.put("node10", 1);
    node00_to_write.put("node11", "lalala");
    node00_to_write.put("node12", JSONObject.NULL);
    node01_to_write.put(true);
    node01_to_write.put(false);
    json_obj_to_write.put("node00", node00_to_write);
    json_obj_to_write.put("node01", node01_to_write);
    System.out.print("The JSON should be: ");
    System.out.println(json_obj_to_write.toString());
  }
}

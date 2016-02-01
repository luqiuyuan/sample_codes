import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.Files;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.BufferedWriter;

public class StreamOrientedFileIO {
  public static void main(String[] args) {
    Path inputFilepath = Paths.get("in.txt");
    Path outputFilepath = Paths.get("out.txt");
    try {
      InputStream is = Files.newInputStream(inputFilepath);
      OutputStream os = Files.newOutputStream(outputFilepath); // Create a new file if the file doesn't exist, or override the file
      BufferedReader reader = new BufferedReader(new InputStreamReader(is));
      BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(os));
      String line;
      while((line = reader.readLine()) != null) {
        writer.write(line+"\n");
      }
      reader.close();
      writer.close();
    } catch (IOException e) {
      System.err.println(e);
    }
  }
}
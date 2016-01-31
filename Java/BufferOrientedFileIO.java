import java.nio.file.FileSystems;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.charset.Charset;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.nio.file.Files;
import java.io.IOException;

public class BufferOrientedFileIO {
  public static void main(String[] args) {
//    Path inputFilepath = Paths.get(".", "in.txt");  // get path from seperate strings
    Path inputFilepath = Paths.get("in.txt");
    Path outputFilepath = Paths.get("out.txt");
    Charset charset = Charset.forName("UTF-8");
    try {
      BufferedReader reader = Files.newBufferedReader(inputFilepath, charset);
      BufferedWriter writer = Files.newBufferedWriter(outputFilepath, charset);  // Create a new file no matter if the file exists
      String line;
      while ((line = reader.readLine()) != null) {
        line += '\n';
        writer.write(line, 0, line.length());
      }
      reader.close();
      writer.close();
    } catch (IOException e) {
      System.err.format("IOException: %s%n", e);
    }
  }
}
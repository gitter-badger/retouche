namespace Persistence {
  Persister* get(const std::string &fileType) {
    if (fileType == "bmp") {
      return new BitmapPersister;
    } else if (fileType == "jpeg") {
      return new JpegPersister;
    }
    return nullptr;
  }
};

#include "rom.h"

std::array<std::uint8_t, MaxFileSize> read_rom_data(std::ifstream &file,
                                                    std::uintmax_t size) {
  std::array<std::uint8_t, MaxFileSize> data{};
  std::copy_n(std::istreambuf_iterator(file), size, data.begin());
  return data;
}

[[nodiscard]] std::optional<Rom> load_rom(std::filesystem::path uri) noexcept {
  if (!std::filesystem::exists(uri))
    return std::nullopt;
  // if(uri.extension() != ".ch8") return std::nullopt;

  auto const size = std::filesystem::file_size(uri);
  if (size > MaxFileSize)
    return std::nullopt;

  std::ifstream file(uri, std::ios::in | std::ios::binary);
  if (!file.is_open())
    return std::nullopt;

  return Rom{
      .name = uri.filename(),
      .size = size,
      .data{read_rom_data(file, size)}
  };
}

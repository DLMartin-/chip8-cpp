#ifndef CHIP8_ROM_H_
#define CHIP8_ROM_H_

#include <algorithm>
#include <array>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <optional>
#include <string>
#include <vector>

constexpr auto MaxFileSize = 1024u;
struct Rom {
  std::string name;
  std::uintmax_t size;
  std::array<std::uint8_t, MaxFileSize> data;
};

[[nodiscard]] std::optional<Rom> load_rom(std::filesystem::path uri) noexcept;
#endif

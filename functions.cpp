#include "functions.hpp"

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <array>
#include <QString>

QString functions::exec(QString cmd) {
  std::array<char, 128> buffer;
  QString result;
  std::shared_ptr<FILE> pipe(popen(cmd.toStdString().c_str(), "r"), pclose);
  //if (!pipe) throw std::runtime_error("popen() failed!");
  while (!feof(pipe.get())) {
    if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
      result += QString::fromUtf8(buffer.data());
  }
  return result;
}
#include <iostream>
#include <optional>
#include <string>

int main()
{
  // #01 @in_place
  auto s = std::optional<std::string>(std::in_place, 5, 'a');

  // #02
  std::cout << "#02 ";
  if (s) {
    std::cout << "s= " << *s << '\n';
  } else {
    std::cout << "null\n";
  }

  // #03 @has_value @value
  std::cout << "#03 ";
  if (s.has_value()) {
    std::cout << "@has_value @value s= " << s.value() << '\n';
  } else {
    std::cout << "null\n";
  }

  // #04 @value_or
  std::cout << "#04 @value_or s= " << s.value_or("null") << '\n';

  // #05 @reset
  s.reset();
  std::cout << "#05 @reset s= " << s.value_or("null") << '\n';

  // #06 @emplace
  s.emplace("abcdef");
  std::cout << "#06 @emplace s= " << s.value_or("null") << '\n';

  // #06 @make_optional
  s = std::make_optional("123456");
  std::cout << "#07 @make_optional s= " << s.value_or("null") << '\n';

  return 0;
}
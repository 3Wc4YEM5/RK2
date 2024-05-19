file(REMOVE_RECURSE
  "check"
  "check.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/check.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()

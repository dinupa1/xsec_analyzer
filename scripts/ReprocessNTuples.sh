#!/bin/bash

# Number of expected command-line arguments
num_expected=3

if [ "$#" -ne "$num_expected" ]; then
  echo "Usage: ./ReprocessNTuples.sh OUTPUT_DIRECTORY SELECTION_NAMES NTUPLE_LIST_FILE"
  exit 1
fi

output_dir=$1
selections=$2
ntuple_list_file=$3

# Verification checks
if [ ! -f "$ntuple_list_file" ]; then
  echo "Ntuple list file \"${ntuple_list_file}\" not found"
  exit 1
fi

if [ ! -d "${output_dir}" ]; then
  echo "Output directory \"${output_dir}\" not found"
  exit 2
fi

# Efficiently read the file list into an array
input_files=()
while read -r line; do
  # Skip comments and empty lines
  if [[ ! $line = \#* ]] && [[ $line = *[^[:space:]]* ]]; then
    input_files+=("$line")
  fi
done < "${ntuple_list_file}"

total_files=${#input_files[@]}
echo "Total number of files = ${total_files}"

counter=0
for file in "${input_files[@]}"
do
    # Extracting columns from the input file
    input_file_name=$(echo "$file" | awk '{print $1}')
    input_file_type=$(echo "$file" | awk '{print $2}')
    run_id=$(echo "$file" | awk '{print $3}')

    # Constructing output path
    output_file_name="${output_dir}/xsec-ana-$(basename "${input_file_name}")"

    echo "------------------------------------------------"
    echo "Processing: $((counter + 1)) / ${total_files}"
    echo "Input:  ${input_file_name}"
    echo "Type:   ${input_file_type}"
    echo "Run ID: ${run_id}"
    echo "Output: ${output_file_name}"

    # CRITICAL: Use quotes around variables to prevent shell splitting
    date
    time ProcessNTuples "${input_file_name}" "${input_file_type}" "${selections}" "${run_id}" "${output_file_name}"
    date

    counter=$((counter + 1))
done

echo "--- All files processed ---"

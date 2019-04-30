import glob

file_name = glob.glob("./*.h")

vector_ext_insn = glob.glob("./v*.h")


# assume normal instruction cost is 1.
# category -> int
insn_category = {
    'int_alu': 1,
    'int_mul': 3,
    'float_alu': 2,
    'mem': 3,
    'V_SIMD_int_alu': 3,
    'V_SIMD_int_mul': 6,
    'V_SIMD_float_alu': 3,
    'V_SIMD_permuation': 3,
    'V_SIMD_int_reduction': 3,
    'V_SIMD_float_reduction': 3,
    'V_SIMD_mem': 6,
    'V_SIMD_setting': 3, 
    'P_SIMD_int_alu': 1,
    'P_SIMD_int_mul': 1,
    'P_SIMD_float_alu': 1,
    'P_SIMD_permuation': 1,
    'P_SIMD_int_reduction': 1
}

# insn_category = {
#     'int_alu': 1,
#     'int_mul': 3,
#     'float_alu': 2,
#     'mem': 3,
#     'V_SIMD_int_alu': 1,
#     'V_SIMD_int_mul': 1,
#     'V_SIMD_float_alu': 1,
#     'V_SIMD_permuation': 1,
#     'V_SIMD_int_reduction': 1,
#     'V_SIMD_float_reduction': 1,
#     'V_SIMD_mem': 1,
#     'V_SIMD_setting': 1, 
#     'P_SIMD_int_alu': 1,
#     'P_SIMD_int_mul': 1,
#     'P_SIMD_float_alu': 1,
#     'P_SIMD_permuation': 1,
#     'P_SIMD_int_reduction': 1
# }

# insn -> int
cycle_count = {
    'vadd_vi': insn_category['V_SIMD_int_alu'],
    'vadd_vs': insn_category['V_SIMD_int_alu'],
    'vadd_vv': insn_category['V_SIMD_int_alu'],
    'vfadd_vf': insn_category['V_SIMD_float_alu'],
    'vfadd_vv': insn_category['V_SIMD_float_alu'],
    'vext_x_s': insn_category['V_SIMD_permuation'],
    'vfmul_vf': insn_category['V_SIMD_float_alu'],
    'vfmul_vv': insn_category['V_SIMD_float_alu'],
    'vfredsum_vs': insn_category['V_SIMD_float_reduction'],
    'vle': insn_category['V_SIMD_mem'],
    'vse': insn_category['V_SIMD_mem'],
    'vlex': insn_category['V_SIMD_mem'],
    'vsex': insn_category['V_SIMD_mem'],
    'vlw': insn_category['V_SIMD_mem'],
    'vsw': insn_category['V_SIMD_mem'],
    'vmul_vs': insn_category['V_SIMD_int_alu'],
    'vmul_vv': insn_category['V_SIMD_int_alu'],
    'vsetvl': insn_category['V_SIMD_setting'],
    'vmv_s_x': insn_category['V_SIMD_permuation'],
    'vredsum_vs': insn_category['V_SIMD_int_reduction'],
    'vslidedown_vi': insn_category['V_SIMD_permuation'],
    'vslidedown_vx': insn_category['V_SIMD_permuation'],
    'vslideup_vi': insn_category['V_SIMD_permuation'],
    'vslideup_vx': insn_category['V_SIMD_permuation'],
    'add16': insn_category['P_SIMD_int_alu'],
    'cras16': insn_category['P_SIMD_int_alu'],
    'crsa16': insn_category['P_SIMD_int_alu'],
    'kadd16': insn_category['P_SIMD_int_alu'],
    'kcras16': insn_category['P_SIMD_int_alu'],
    'kcrsa16': insn_category['P_SIMD_int_alu'],
    'khm16': insn_category['P_SIMD_int_alu'],
    'ksll16': insn_category['P_SIMD_int_alu'],
    'ksub16': insn_category['P_SIMD_int_alu'],
    'pkbb16': insn_category['P_SIMD_permuation'],
    'pkbt16': insn_category['P_SIMD_permuation'],
    'pltb16': insn_category['P_SIMD_permuation'],
    'pktt16': insn_category['P_SIMD_permuation'],
    'radd16': insn_category['P_SIMD_int_alu'],
    'rcras16': insn_category['P_SIMD_int_alu'],
    'rcrsa16': insn_category['P_SIMD_int_alu'],
    'rsub16': insn_category['P_SIMD_int_alu'],
    'smax16': insn_category['P_SIMD_int_reduction'],
    'smin16': insn_category['P_SIMD_int_reduction'],
    'sub16': insn_category['P_SIMD_int_alu'],
    'ukadd16': insn_category['P_SIMD_int_alu'],
    'ukcras16': insn_category['P_SIMD_int_alu'],
    'ukcrsa16': insn_category['P_SIMD_int_alu'],
    'uksub16': insn_category['P_SIMD_int_alu'],
    'umax16': insn_category['P_SIMD_int_reduction'],
    'umin16': insn_category['P_SIMD_int_reduction'],
    'uradd16': insn_category['P_SIMD_int_alu'],
    'urcras16': insn_category['P_SIMD_int_alu'],
    'urcrsa16': insn_category['P_SIMD_int_alu'],
    'ursub16': insn_category['P_SIMD_int_alu'],
    'add8': insn_category['P_SIMD_int_alu'],
    'kadd8': insn_category['P_SIMD_int_alu'],
    'khm8': insn_category['P_SIMD_int_mul'],
    'ksll8': insn_category['P_SIMD_int_alu'],
    'ksub8': insn_category['P_SIMD_int_alu'],
    'radd8': insn_category['P_SIMD_int_alu'],
    'rsub8': insn_category['P_SIMD_int_alu'],
    'smax8': insn_category['P_SIMD_int_reduction'],
    'smin8': insn_category['P_SIMD_int_reduction'],
    'sub8': insn_category['P_SIMD_int_alu'],
    'ukadd8': insn_category['P_SIMD_int_alu'],
    'uksub8': insn_category['P_SIMD_int_alu'],
    'umax8': insn_category['P_SIMD_int_reduction'],
    'umin8': insn_category['P_SIMD_int_reduction'],
    'uradd8': insn_category['P_SIMD_int_alu'],
    'ursub8': insn_category['P_SIMD_int_alu'],
    'lui': insn_category['int_alu'],
    'auipc': insn_category['int_alu'],
    'jal': insn_category['int_alu'],
    'jalr': insn_category['int_alu'],
    'beq': insn_category['int_alu'],
    'bne': insn_category['int_alu'],
    'lw': insn_category['mem'],
    'ld': insn_category['mem'],
    'sw': insn_category['mem'],
    'sd': insn_category['mem'],
    'vext_x_v': insn_category['V_SIMD_permuation'],
    
}

insn_category = {
    'vadd_vi': 'V',
    'vadd_vs': 'V',
    'vadd_vv': 'V',
    'vfadd_vf': 'V',
    'vfadd_vv': 'V',
    'vext_x_v': 'V',
    'vfmul_vf': 'V',
    'vfmul_vv': 'V',
    'vfredsum_vs': 'V',
    'vle': 'V',
    'vse': 'V',
    'vmul_vs': 'V',
    'vmul_vv': 'V',
    'vsetvl': 'V',
    'vmv_s_x': 'V',
    'vredsum_vs': 'V',
    'vslidedown_vi': 'V',
    'vslidedown_vx': 'V',
    'vslideup_vi': 'V',
    'vslideup_vx': 'V',
    'vlex': 'V',
    'vsex': 'V',
    'vlw': 'V',
    'vsw': 'V',
    'add16': 'P',
    'cras16': 'P',
    'crsa16': 'P',
    'kadd16': 'P',
    'kcras16': 'P',
    'kcrsa16': 'P',
    'khm16': 'P',
    'ksll16': 'P',
    'ksub16': 'P',
    'pkbb16': 'P',
    'pkbt16': 'P',
    'pltb16': 'P',
    'pktt16': 'P',
    'radd16': 'P',
    'rcras16': 'P',
    'rcrsa16': 'P',
    'rsub16': 'P',
    'smax16': 'P',
    'smin16': 'P',
    'sub16': 'P',
    'ukadd16': 'P',
    'ukcras16': 'P',
    'ukcrsa16': 'P',
    'uksub16': 'P',
    'umax16': 'P',
    'umin16': 'P',
    'uradd16': 'P',
    'urcras16': 'P',
    'urcrsa16': 'P',
    'ursub16': 'P',
    'add8': 'P',
    'kadd8': 'P',
    'khm8': 'P',
    'ksll8': 'P',
    'ksub8': 'P',
    'radd8': 'P',
    'rsub8': 'P',
    'smax8': 'P',
    'smin8': 'P',
    'sub8': 'P',
    'ukadd8': 'P',
    'uksub8': 'P',
    'umax8': 'P',
    'umin8': 'P',
    'uradd8': 'P',
    'ursub8': 'P',
    'lui': 'B',
    'auipc': 'B',
    'jal': 'B',
    'jalr': 'B',
    'beq': 'B',
    'bne': 'B',
    'lw': 'B',
    'ld': 'B',
    'sw': 'B',
    'sd': 'B',
}

marco_function = ['ALL_INSN_count', 'ALL_INSN_cycle', 'P_EXT_count', 'P_EXT_cycle', 'V_EXT_count', 'V_EXT_cycle']

for file_path in file_name:
    all_file = ''
    with open(file_path, "r") as f:
        for line in f:
            if "ALL_INSN_count" in line:
                pass
            elif "ALL_INSN_cycle" in line:
                pass
            elif "P_EXT_count" in line:
                pass
            elif "P_EXT_cycle" in line:
                pass
            elif "V_EXT_count" in line:
                pass
            elif "V_EXT_cycle" in line:
                pass
            else:
                all_file += line

    insn_name = file_path.replace(".h", "")[2:]
    
    with open(file_path, "w") as f:
        f.write(all_file + "\n")
        f.write("ALL_INSN_count;\n")
        if insn_name not in insn_category:
            f.write("ALL_INSN_cycle(1);\n")
            pass
        elif insn_category[insn_name] == 'B':
            f.write("ALL_INSN_cycle({});\n".format(cycle_count[insn_name]))
        elif insn_category[insn_name] == 'V':
            f.write("V_EXT_count;\n")
            f.write("V_EXT_cycle({});\n".format(cycle_count[insn_name]))
            f.write("ALL_INSN_cycle({});\n".format(cycle_count[insn_name]))
        elif insn_category[insn_name] == 'P':
            f.write("P_EXT_count;\n")
            f.write("P_EXT_cycle({});\n".format(cycle_count[insn_name]))
            f.write("ALL_INSN_cycle({});\n".format(cycle_count[insn_name]))
        else:
            pass
            
    

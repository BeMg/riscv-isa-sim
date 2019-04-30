require_extension('A');
require_rv64;
WRITE_RD(MMU.amo_uint64(RS1, [&](int64_t lhs) { return std::max(lhs, int64_t(RS2)); }));
ALL_INSN_ADD1;














ALL_INSN_count;
ALL_INSN_cycle(1);

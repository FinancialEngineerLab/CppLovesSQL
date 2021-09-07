
                    string strSQL = @"INSERT INTO HoldingList SELECT

                                             '@Date', '@ProductCode',

                                             '@Type', NULL,

                                             case

                                                        when kontrh = '3051471713' then 'CA'

                                                        when kontrh = '4007143724' then 'BNP'

                                                        when kontrh = '6007142596' then 'CITI'

                                                        when kontrh = '7055741277' then 'MS'

                                                        when kontrh = '8058923498' then 'JPM'

                                                        when kontrh = '9007001879' then 'KYOBO'

                                                        else NULL

                                             end,

                                             case

                                                        when right('@ProductCode', 1) = 'R' then -1

                                                        when right('@ProductCode', 1) = 'P' then 1

                                                        else -1

                                             end,

                                             cast(fnotionalp as numeric) * 100,

                                             '@UserId'

                                      

                                       from ZFCFM_MCI_OTC001

                                       where '@ProductCode'

                                                        = (RIGHT(xvtrab, 6) + 'IRS'

                                                        + REPLICATE('0', 2 - LEN(CAST(FLOOR(DATEDIFF(DD, xlavo, xlabi) / 365.0) AS VARCHAR)))

                                                        + CAST(FLOOR(DATEDIFF(DD, xlavo, xlabi) / 365.0) AS VARCHAR)

                                               + 'Y'

                                                        + CASE WHEN CAST(pzinssvn AS float) = 0 THEN REPLICATE('0', 6 - LEN(CONVERT(VARCHAR(6), CONVERT(FLOAT, pzinssv) * 10000)))

                                                        + CONVERT(VARCHAR(6), CONVERT(FLOAT, pzinssv) * 10000)

                                                        + 'P' ELSE REPLICATE('0', 6 - LEN(CONVERT(VARCHAR(6), CONVERT(FLOAT, pzinssvn) * 10000)))

                                                        + CONVERT(VARCHAR(6), CONVERT(FLOAT, pzinssvn) * 10000)

                                               + 'R' END)

 

                                      delete from hanwhainput.dbo.IRSwap where SwapCode = '@ProductCode'

                                      exec IRSwap_Update '@ProductCode'";
